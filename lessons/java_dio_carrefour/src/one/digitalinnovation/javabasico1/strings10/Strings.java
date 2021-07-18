package one.digitalinnovation.javabasico1.strings10;

public class Strings {
    public static void main(String[] args) {

        var nome = "andre";
        var sobreNome = "gomes";
        final var nomeCompleto = nome + sobreNome;

        System.out.println(nome);
         //andre
        System.out.println("nome do cliente: " + nome);
          //nome do cliente: andre
        System.out.println("nome completo do cliente: " + nomeCompleto);
          //nome completo do cliente: andregomes
        var string = new String("  minha string  ");

        System.out.println("char na posicao 5: " + string.charAt(5));
          //char na posicao 5: h
        System.out.println("quantidade= " + string.length());
          //quantidade= 16
        System.out.println("sem trim [" + string + "]");
          //sem trim [  minha string  ]
        System.out.println("com trim [" + string.trim() + "]");
          //com trim [minha string]
        System.out.println("lower " + string.toLowerCase());
          //lower   minha string
        System.out.println("upper " + string.toUpperCase());
          //upper   MINHA STRING
        System.out.println("contem m? " + string.contains("m"));
          //contem m? true
        System.out.println("contem x? " + string.contains("x"));
          //contem x? false
        System.out.println("replace " + string.replace("n", "$"));
          //replace   mi$ha stri$g
        System.out.println("equals " + string.equals("  minha string  "));
          //equals true
        System.out.println("equals ignore case " + string.equalsIgnoreCase("  Minha String  "));
          //equals ignore case true
        System.out.println("substring(1,6):\n" + string.substring(1, 6));
          //substring(1,6)  minh

    }
}
