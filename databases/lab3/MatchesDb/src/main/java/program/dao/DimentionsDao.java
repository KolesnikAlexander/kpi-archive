package program.dao;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import org.hibernate.Session;
import org.hibernate.query.Query;
import program.Settings;
import program.entity.DimentionEntity;
import program.entity.GameEntity;
import program.orm.Championship;
import program.orm.Club;
import program.orm.HibernateUtil;
import program.orm.Stadium;

import java.io.File;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;


/**
 * Created by alex60070
 */
public class DimentionsDao {
    public static ObservableList<DimentionEntity> readClubs(){

        Session session = HibernateUtil.getSessionFactory().openSession();
        session.beginTransaction();
        Query clubQuery = session.createQuery("from Club");
        List<Club> clubs = clubQuery.list();
        session.getTransaction().commit();

        ObservableList<DimentionEntity> dimentions = FXCollections.observableArrayList();
        System.out.println("READ DATA: ");
        for (Club club: clubs) {
            System.out.println(club);
            dimentions.add(new DimentionEntity(club.getName(),club.getId()));
        }
        return dimentions;

//        String query = "SELECT name, club_id \n"+
//                "FROM matches.club;";
//        return executeReadQuery(query);
    }
    public static ObservableList<DimentionEntity> readStadiums(){
        Session session = HibernateUtil.getSessionFactory().openSession();
        session.beginTransaction();
        Query query = session.createQuery("from Stadium");
        List<Stadium> items = query.list();
        session.getTransaction().commit();

        ObservableList<DimentionEntity> dimentions = FXCollections.observableArrayList();
        System.out.println("READ DATA Stad: ");
        for (Stadium item: items) {
            System.out.println(item);
            dimentions.add(new DimentionEntity(item.getName(),item.getId()));
        }
        return dimentions;
//        String query = "SELECT name, stadium_id \n"+
//                "FROM matches.stadium;";
//        return executeReadQuery(query);
    }
    public static ObservableList<DimentionEntity> readChampionships(){
        Session session = HibernateUtil.getSessionFactory().openSession();
        session.beginTransaction();
        Query query = session.createQuery("from Championship");
        List<Championship> items = query.list();
        session.getTransaction().commit();

        ObservableList<DimentionEntity> dimentions = FXCollections.observableArrayList();
        System.out.println("READ DATA Champ: ");
        for (Championship item: items) {
            System.out.println(item);
            dimentions.add(new DimentionEntity(item.getName(),item.getId()));
        }
        return dimentions;
//        String query = "SELECT name, championship_id \n"+
//                "FROM matches.championship;";
//        return executeReadQuery(query);
    }

    public static boolean uploadStadiums(){
        File file = new File(Settings.STADIUM_XML_PATH);
        System.out.println(file.getAbsolutePath());
        String query = "LOAD XML LOCAL INFILE '"+file.getAbsolutePath()+"'" +
                "  INTO TABLE matches.stadium\n" +
                "  ROWS IDENTIFIED BY '<row>';";
        return GamesDao.executeUpdateQuery(query);
    }
    public static boolean uploadClubs(){
        File file = new File(Settings.CLUB_XML_PATH);
        System.out.println(file.getAbsolutePath());
        String query = "LOAD XML LOCAL INFILE '"+file.getAbsolutePath()+"'" +
                "  INTO TABLE matches.club\n" +
                "  ROWS IDENTIFIED BY '<row>';";
        return GamesDao.executeUpdateQuery(query);
    }
    public static boolean uploadChampionships(){
        File file = new File(Settings.CHAMPIONSHIP_XML_PATH);
        System.out.println(file.getAbsolutePath());
        String query = "LOAD XML LOCAL INFILE '"+file.getAbsolutePath()+"'" +
                "  INTO TABLE matches.championship\n" +
                "  ROWS IDENTIFIED BY '<row>';";
        return GamesDao.executeUpdateQuery(query);
    }

    public static ObservableList<DimentionEntity> executeReadQuery(String query){
        Statement statement = GamesDao.connect();
        ResultSet resultSet = null;
        try {
            resultSet = statement.executeQuery(query);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return parseEntities(resultSet);
    }
    private static ObservableList<DimentionEntity> parseEntities(ResultSet resultSet){
        ObservableList<DimentionEntity> dimentions = FXCollections.observableArrayList();
        DimentionEntity dimention = null;
        String strVal;
        int intVal;
        try {
            while (resultSet.next()){
                strVal = resultSet.getString(1);
                intVal = resultSet.getInt(2);
                dimentions.add(new DimentionEntity(strVal, intVal));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return dimentions;
    }
}
