package program;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.hibernate.Session;
import org.hibernate.query.Query;
import program.dao.GamesDao;
import program.orm.*;

import java.util.Date;
import java.util.List;

public class Main extends Application {


    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(Main.class.getResource("/res/main.fxml"));
        Parent root = loader.load();
        primaryStage.setTitle("DB Lab 2");
        primaryStage.setScene(new Scene(root, 1000, 750));
        primaryStage.show();

        Controller controller = loader.getController();
        controller.loadGameTable();

        hibernateTest();

    }

    private void hibernateTest() {
        System.out.println("Maven + Hibernate + MySQL");
        Session session = HibernateUtil.getSessionFactory().openSession();


//        Stadium stadium = new Stadium();
//
//        stock.setStockCode("4715");
//        stock.setStockName("GENM");

//        session.
//        session.save(stock);
//        session.getTransaction().commit();




//        session.beginTransaction();
//        Query query = session.createQuery("from Game");
//        List<Game> list = query.list();
//
//        for (Game item: list) {
//            System.out.println(item);
//        }
//        session.getTransaction().commit();




//        session = HibernateUtil.getSessionFactory().openSession();
//        session.beginTransaction();
//        Game game = new Game();
//        game.setHostClubId(new Integer(85));
//        game.setGuestClubId(86);
//        game.setStadiumId(24);
//        game.setChampionshipId(77);
//        game.setDate(new Date(2012,3,5));
//        game.setScore("300-300");
//
//        session.save(game);
//        session.getTransaction().commit();






//
//        session = HibernateUtil.getSessionFactory().openSession();
//        session.beginTransaction();
//        Game gameUpdate = new Game();
//        gameUpdate.setGameId(4);
//        gameUpdate.setHostClubId(new Integer(85));
//        gameUpdate.setGuestClubId(86);
//        gameUpdate.setStadiumId(24);
//        gameUpdate.setChampionshipId(77);
//        gameUpdate.setDate(new Date(2012,3,5));
//        gameUpdate.setScore("7-100");
//
//        session.update(gameUpdate);
//        session.getTransaction().commit();

        System.out.println("Stored: "+GamesDao.storedProcedure());

    }


    public static void main(String[] args) {
        launch(args);
    }
}
