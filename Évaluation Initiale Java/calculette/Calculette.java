package calculette;

/**
 * La classe Calculette a pour but d'évaluer une expression arithmétique.
 *
 * - L'expression est donnée sous forme de tableau de caractères.
 * - L'expression ne contient que des entiers et des opérateurs +, -, * ou /.
 * - L'expression ne contient pas de parenthèse ou de nombre à virgule\n" +
 * (mais le résultat de l'expression peut être un réel, par exemple 10/3 =
 * 3.33333...)
 * Note: On ne tiendra pas compte de la priorité des opérateurs: 3+2*2
 * retournera 10 et non 7.
 *
 * Exemple avec l'expression "15-3*10", on aura le tableau expression:
 * -------------------------------------------
 * valeur | '1' | '5' | '-' | '3' | '*' | '1' | '0' |
 * |-----|-----|-----|-----|-----|-----|-----|
 * indice |--0--|--1--|--2--|--3--|--4--|--5--|--6--|
 * -------------------------------------------
 *
 * Le résultat de l'appel à la méthode evalue sur le tableau précédant devra
 * être 120
 * (rappel: on ne tien pass compte de la priorité des opérateurs)
 *
 * Tip: pour obtenir la valeur 5 à partir du charactère '5', on peut utiliser le
 * code suivant:
 * char c = '5';
 * int i = c - '0'; // ici, i vaut le nombre 5
 *
 * Tip: pour savoir si un caractère est un chiffre, on peut utiliser la méthode
 * Java:
 * boolean Character.isDigit(char ch)
 *
 * /!\ Ne pas ajouter de méthode
 *
 * /!\ Ne rien écrire en dehors des méthodes
 *
 * /!\ Correction automatique: n'envoyer votre code QUE lorsque qu'il compile !!
 */
public class Calculette {

    /**
     * Variables d'instance: vous pouvez utiliser ces variables dans toutes les
     * méthodes ci-dessous.
     */
    // Indice courant de l'expression: il gardera la valeur que vous lui donnerez
    // dans d'une méthode à l'autre. Il est conseillé de l'utiliser comme marqueur
    // de lecture l'expression à évaluer (indice courant du tableau).
    int indiceCourant;

    // Expression sous forme de tableau de caractères.
    char[] expression;

    /**
     * Calcule et renvoie la valeur de l'expression v1 operateur v2
     * Renvoie 0.0 si l'opérateur n'est aucun de ceux autorisé
     *
     * Exemples:
     * v1 = 4, v2 = 6 et operateur = '+', renvoie 10
     * v1 = 4, v2 = 2 et operateur = '-', renvoie 2
     */
    public double valeur(double v1, char operateur, double v2) 
    {
        switch (operateur)
        {
        case '+': return v1+v2; 
        case '-': return v1-v2; 
        case '/': return v1/v2; 
        case '*': return v1*v2; 
        default : return 0.0;  
        
        }
    }

    /**
     * Renvoie l'opérateur situé à la place indiceCourant du tableau expression sous
     * forme de caractère (char).
     *
     * Si aucun élément trouvé ou si l'élément trouvé n'est pas un opérateur permis
     * (+, -, * ou /),
     * renvoie le caractère 'N'
     */
    public char lireOperateur() {
        //(expression[indiceCourant]=='') 
       
        if (indiceCourant < expression.length) {
            char op = expression[indiceCourant];
            if (op == '+' || op == '-' || op == '*' || op == '/') {
                indiceCourant++; // Avancer l'indice pour la prochaine lecture
                return op;
            }
        }
        return 'N'; // Retourner 'N' si aucun opérateur valide n'est trouvé
    }

        
       
        
    }

    /**
     * Lit l'opérande (i.e. le nombre) situé à la case indiceCourant du tableau
     * expression
     * Attention: il peut s'agir d'un nombre à plusieurs chiffres !
     *
     * Tip: pour obtenir la valeur 5 à partir du charactère '5', on peut utiliser le
     * code suivant:
     * char c = '5';
     * int i = c - '0'; // ici, i vaut le nombre 5
     */
    public int lireOperande() {
         while (indiceCourant<expression.length)
       { if (expression[indiceCourant]!='+' || expression[indiceCourant]!= '/' || expression[indiceCourant]!= '*' || expression[indiceCourant]!='-')
        return expression[indiceCourant]-'0';
       }
       return expression[indiceCourant]-'0';
    }

    /**
     * Evalue l'expression passée en paramètre et renvoie soin résultat sous forme
     * de nombre réel.\n
     */
    public double evalue(char[] exp) {
        /* TODO  
       double resultat = 0.0;
        expression = exp;
        indiceCourant = 0;
        int tailleTableau = expression.length;
        
        double op1;
        double op2;
        char operateur;
        
       // 4- Dé-commenter le code ci-dessus puis compléter...
*/
        return 0;
    }
}
