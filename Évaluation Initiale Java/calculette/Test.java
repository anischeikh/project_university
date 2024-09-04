package calculette;

import java.io.IOException;

public class Test {

    public static void main(String[] args) throws IOException {
        Calculette calc = new Calculette();
        System.out.println("--- Test de la méthode valeur");
        System.out.println("valeur(12, '+', 5) = " + calc.valeur(12, '+', 5));
        System.out.println("valeur(2, '-', 6) = " + calc.valeur(2, '-', 6));
        System.out.println("valeur(5, '*', 2) = " + calc.valeur(5, '*', 2));
        System.out.println("valeur(14, '/', 3) = " + calc.valeur(14, '/', 3));
        System.out.println("valeur(14, '$', 3) = " + calc.valeur(14, '/', 3));
        String expressionStr = "15-3*10";
        System.out.println("Dans la suite, on utilise l'expressions suivante: ");
        System.out.println(expressionAsTable(expressionStr));
        calc.expression = expressionStr.toCharArray();
        System.out.println("--- Test de la méthode lireOperateur");
        calc.indiceCourant = 4;
        char c = calc.lireOperateur();
        System.out.println("L'opérateur lu à l'indice 4 est : " + c);
        calc.indiceCourant = 0;
        System.out.println("--- Test de la méthode lireOperateur");
        System.out.println("La méthode lireOperande à l'indice 0 renvoie : " + calc.lireOperande());
    }

    public static String expressionAsTable(String exp) {
        String res;
        char[] expression = exp.toCharArray();
        res = "Expression: \n";
        res += "-";
        for (int i = 0; i < expression.length; i++) {
            res += "------";
        }
        res += "\n";
        res += "|";
        for (char c : expression) {
            res += " '" + c + "' |";
        }
        res += "\n";
        res += "|";
        for (int i = 0; i < expression.length; i++) {
            res += "-----|";
        }
        res += "\n";
        res += "|";
        for (int i = 0; i < expression.length; i++) {
            res += "--" + i + "--|";
        }
        res += "\n";
        res += "-";
        for (int i = 0; i < expression.length; i++) {
            res += "------";
        }
        return res;
    }
}
