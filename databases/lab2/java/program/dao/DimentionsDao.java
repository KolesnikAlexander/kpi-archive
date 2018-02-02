package program.dao;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import program.entity.DimentionEntity;
import program.entity.GameEntity;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import static program.dao.GamesDao.executeReadQuery;

/**
 * Created by alex60070
 */
public class DimentionsDao {
    public static ObservableList<DimentionEntity> readClubs(){
        String query = "SELECT name, club_id \n"+
                "FROM matches.club;";
        return executeReadQuery(query);
    }
    public static ObservableList<DimentionEntity> readStadiums(){
        String query = "SELECT name, stadium_id \n"+
                "FROM matches.stadium;";
        return executeReadQuery(query);
    }
    public static ObservableList<DimentionEntity> readChampionships(){
        String query = "SELECT name, championship_id \n"+
                "FROM matches.championship;";
        return executeReadQuery(query);
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
