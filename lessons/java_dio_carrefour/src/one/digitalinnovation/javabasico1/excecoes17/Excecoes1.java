package one.digitalinnovation.javabasico1.excecoes17;

public class Excecoes1 {
    public static void main(String[] args) {

        try{
            new java.io.FileInputStream("arquivo.txt");
        } catch(java.io.FileNotFoundException e){
            System.out.println("nao foi possivel abrir arquivo para leitura");
        }

          /*//exemplo de erro de criacao de objeto personalizado
        try{
            CarroVo carro = new CarroVo();
            carro.getPlaca();
        } catch (IntegrationException e){
            throw new BussinessException("erro na criacao do objeto", e);
        }*/

          /*//exemplo com finnaly
        try{
            PrepareStatement stmt = con.prepareStatement(query);
        } catch (SQLException e){
            throw new AcessoADadosException("problema na criacao de statement", e)
        } finally {
            stmt.close();
        }*/


    }

      //exemplo de metodo preparado para lidar com excecao
/*    public static void recuperarIdUsuario(String query) throws AcessoADadosException{

        try{
            PreparedStatement stmt = con.prepareStatement(query);
        } catch (SQLException e){
            throw new AcessoADadosException("problema na criacao do statement", e)
        } finally{
            stmt.close();
        }
    }*/
}
