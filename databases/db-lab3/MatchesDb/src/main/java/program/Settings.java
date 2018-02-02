package program;

public class Settings {
    public static final String dbUrl = "jdbc:mysql://127.0.0.1:3306/matches?characterEncoding=UTF-8" +
            "&autoReconnect=true&useSSL=false";
    public static final String dbUser = "root";
    public static final String dbPassword = "password";

    public static final String CLUB_XML_PATH = "clubs.xml";
    public static final String CHAMPIONSHIP_XML_PATH = "championships.xml";
    public static final String STADIUM_XML_PATH = "stadiums.xml";
}