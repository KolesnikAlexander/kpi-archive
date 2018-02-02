package program.dao;

import com.mysql.fabric.jdbc.FabricMySQLDriver;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import program.Settings;
import program.entity.GameEntity;

import java.sql.*;
import java.time.LocalDate;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by alex60070
 */
public class GamesDao {
    public static ObservableList<GameEntity> readNoFilter(){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id";
        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> championshipTopRated(){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE matches.championship.top_rated = 1";

        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> clubTopRated(){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE host.top_rated = 1 OR guest.top_rated = 1";

        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> stadiumTopRated(){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE stadium.top_rated = 1";

        return executeReadQuery(query);
    }

    public static ObservableList<GameEntity> championshipEstabDate(int from, int to){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE championship.estab_date BETWEEN '"+from+"/01/01' AND '"+to+"/01/01';";

        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> clubEstabDate(int from,int to){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE (host.estab_date BETWEEN '"+from+"/01/01' AND '"+to+"/01/01')\n" +
                "AND (guest.estab_date BETWEEN '"+from+"/01/01' AND '"+to+"/01/01');";

        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> stadiumEstabDate(int from,int to){
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE stadium.estab_date BETWEEN '"+from+"/01/01' AND '"+to+"/01/01';";

        return executeReadQuery(query);
    }
    public static ObservableList<GameEntity> wordsSearch(String words){
        System.out.println("WORKED: "+words);
        String query = "SELECT game.game_id, host.name as host_name, \n" +
                "guest.name as guest_name, stadium.name as stadium_name, \n" +
                "championship.name as championship_name, game.score, game.date,\n" +
                "game.host_club_id, game.guest_club_id, game.stadium_id, game.championship_id\n" +
                "FROM matches.game\n" +
                "JOIN matches.club as host ON game.host_club_id = host.club_id\n" +
                "JOIN matches.club as guest ON game.guest_club_id = guest.club_id\n" +
                "JOIN matches.championship ON game.championship_id = championship.championship_id\n" +
                "JOIN matches.stadium ON game.stadium_id = stadium.stadium_id\n" +
                "WHERE match(host.description) against ('"+words+"' in boolean mode)";

        return executeReadQuery(query);
    }

    public static boolean insertGame(GameEntity game){
        int championshipId = game.getChampionshipId();
        int stadiumId = game.getStadiumId();
        int hostClubId = game.getHostClubId();
        int guestClubId = game.getGuestClubId();
        LocalDate date = game.getDate();
        int year = date.getYear();
        int month = date.getMonthValue();
        int day = date.getDayOfMonth();
        String score = game.getScore();

        String query = "INSERT INTO `matches`.`game`(`championship_id`, `stadium_id`," +
                "host_club_id, guest_club_id, date, score) values ('" +
                championshipId+"','"+
                stadiumId+"','"+
                hostClubId+"','"+
                guestClubId+"','"+
                +year+"-"+month+"-"+day+"','"+
                score+"')";

        System.out.println("QUERY: "+query);

        return executeUpdateQuery(query);
    }


    public static boolean updateGame(GameEntity game){
        int gameId = game.getGameId();
        int championshipId = game.getChampionshipId();
        int stadiumId = game.getStadiumId();
        int hostClubId = game.getHostClubId();
        int guestClubId = game.getGuestClubId();
        LocalDate date = game.getDate();
        int year = date.getYear();
        int month = date.getMonthValue();
        int day = date.getDayOfMonth();
        String score = game.getScore();

        //UPDATE `matches`.`game` SET `championship_id`='2', `host_club_id`='3' WHERE `game_id`='7';


        String query = "UPDATE `matches`.`game` SET " +
                "championship_id = '" + championshipId+"',"+
                "stadium_id = '"+stadiumId+"',"+
                "host_club_id = '"+hostClubId+"',"+
                "guest_club_id = '"+guestClubId+"',"+
                "date = '"+year+"-"+month+"-"+day+"',"+
                "score = '"+score+"' "+
                "WHERE game_id = '"+gameId+"';";

        System.out.println("QUERY: "+query);

        return executeUpdateQuery(query);
    }
    public static boolean deleteGame(GameEntity game){
        int gameId = game.getGameId();

        String query = "DELETE FROM `matches`.`game`"+
                " WHERE game_id="+gameId;

        return executeUpdateQuery(query);
    }


    public static boolean executeUpdateQuery(String query){
        Statement statement = connect();
        ResultSet resultSet = null;
        try {
            statement.executeUpdate(query);
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
    public static ObservableList<GameEntity> executeReadQuery(String query){
        Statement statement = connect();
        ResultSet resultSet = null;
        try {
            resultSet = statement.executeQuery(query);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return parseEntities(resultSet);
    }
    private static ObservableList<GameEntity> parseEntities(ResultSet resultSet){
        ObservableList<GameEntity> games = FXCollections.observableArrayList();
        GameEntity game;
        try {
            while (resultSet.next()){
                game = new GameEntity();
                int intVal;
                String strVal;

                intVal = Integer.parseInt(resultSet.getString(1));
                game.setGameId(intVal);

                strVal = resultSet.getString(2);
                game.setHostClub(strVal);

                strVal = resultSet.getString(3);
                game.setGuestClub(strVal);

                strVal = resultSet.getString(4);
                game.setStadium(strVal);

                strVal = resultSet.getString(5);
                game.setChampionship(strVal);

                strVal = resultSet.getString(6);
                game.setScore(strVal);

                java.sql.Date sqlDate = resultSet.getDate(7);
                ArrayList<Integer> dateInts = parseDate(sqlDate.toString());
                game.setDate(dateInts.get(0), dateInts.get(1), dateInts.get(2));

                intVal = resultSet.getInt(8);
                game.setHostClubId(intVal);

                intVal = resultSet.getInt(9);
                game.setGuestClubId(intVal);

                intVal = resultSet.getInt(10);
                game.setStadiumId(intVal);

                intVal = resultSet.getInt(11);
                game.setChampionshipId(intVal);

                games.add(game);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return games;
    }

    public static ArrayList<Integer> parseDate(String date) {

        Pattern usrIdPattern = Pattern.compile("^(.*)-(.*)-(.*)$",
                Pattern.CASE_INSENSITIVE);
        Matcher matcher = usrIdPattern.matcher(date);

        if(!matcher.find()){
            System.out.println("Cannot parse date");
            return null;
        }
            int year = Integer.parseInt(matcher.group(1));
            int month = Integer.parseInt(matcher.group(2));
            int day = Integer.parseInt(matcher.group(3));

            ArrayList<Integer> integers = new ArrayList<>(3);
            integers.add(year);
            integers.add(month);
            integers.add(day);

            return integers;
    }

    public static Statement connect(){
        Statement statement = null;
        try {
            Driver driver = new FabricMySQLDriver();
            DriverManager.registerDriver(driver);
            Connection connection = DriverManager
                    .getConnection(Settings.dbUrl, Settings.dbUser, Settings.dbPassword);
            statement = connection.createStatement();
        } catch (SQLException e) {
            System.out.println("Cannot connect to database");
            e.printStackTrace();
        }finally {
        }

        return statement;
    }


}
