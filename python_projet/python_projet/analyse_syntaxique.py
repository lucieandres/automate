import sys
from sly import Parser
from analyse_lexicale import FloLexer
import arbre_abstrait

class FloParser(Parser):
    # On récupère la liste des lexèmes de l'analyse lexicale
    tokens = FloLexer.tokens
    
    # Définition des priorités
    precedence = (
        #('left', 'ET', 'OU'),
        #('left', 'EGAL', 'NON_EGAL', 'INFERIEUR_EGAL', 'SUPERIEUR_EGAL', 'INFERIEUR', 'SUPERIEUR'),
        ('left', '+', '-'),
        ('left', '*', '/', '%'),
        #('left', '^'),
        #('right', 'UMOINS'),
        ('left', '(', ')')
    )

    # Règles gramaticales et actions associées

    @_('listeInstructions')
    def prog(self, p):
        return arbre_abstrait.Programme(p[0])

    @_('instruction')
    def listeInstructions(self, p):
        l = arbre_abstrait.ListeInstructions()
        l.instructions.append(p[0])
        return l
                    
    @_('instruction listeInstructions')
    def listeInstructions(self, p):
        p[1].instructions.append(p[0])
        return p[1]
        
    @_('ecrire',
       'affectation',
       'nomFonction')
    def instruction(self, p):
        return p[0]
    
    @_('lire')
    def facteur(self,p):
        return arbre_abstrait.Lire()

    @_('ECRIRE "(" expr ")" ";"')
    def ecrire(self, p):
        return arbre_abstrait.Ecrire(p.expr) #p.expr = p[2]

    @_('LIRE "(" ")" ";"')
    def lire(self, p):
        return arbre_abstrait.Lire()
    
    @_('IDENTIFIANT "(" ")" ";"')
    def nomFonction(self, p):
        return arbre_abstrait.Fonction(p.IDENTIFIANT)
    
    @_('expr "+" expr',
       'expr "-" expr',
       'expr "*" expr',
       'expr "/" expr',
       'expr "%" expr',
       'expr "<" expr',
       'expr ">" expr',
       'expr EGAL expr',
       'expr NON_EGAL expr',
       'expr INFERIEUR_EGAL expr',
       'expr SUPERIEUR_EGAL expr',)
    def expr(self, p):
        return arbre_abstrait.Operation(p[1], p[0], p[2])
        
    @_('ENTIER')
    def expr(self, p):
        return arbre_abstrait.Entier(p.ENTIER) #p.ENTIER = p[0]
    
    @_('factor')
    def expr(self, p):
        return p[0]
    
    @_('ENTIER')
    def factor(self, p):
        return arbre_abstrait.Entier(p.ENTIER)

    @_('IDENTIFIANT')
    def factor(self, p):
        return arbre_abstrait.Variable(p.IDENTIFIANT)
    
    @_('IDENTIFIANT "=" expr ";"')
    def affectation(self, p):
        return arbre_abstrait.Affectation(p.IDENTIFIANT, p.expr)
    


if __name__ == '__main__':
    lexer = FloLexer()
    parser = FloParser()
    if len(sys.argv) < 2:
        print("usage: python3 analyse_syntaxique.py NOM_FICHIER_SOURCE.flo")
    else:
        with open(sys.argv[1],"r") as f:
            data = f.read()
            try:
                arbre = parser.parse(lexer.tokenize(data))
                arbre.afficher()
            except EOFError:
                exit()
