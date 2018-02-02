package program.orm;

import java.sql.Date;
import java.time.LocalDate;

/**
 * Created by alex60070
 */
public class Game {
    private Integer gameId;
    private Integer hostClubId;
    private Integer guestClubId;
    private Integer stadiumId;
    private Integer championshipId;
    private Date date;
    private String score;


    public Game() {}

    public Integer getGameId() {
        return gameId;
    }

    public void setGameId(Integer gameId) {
        this.gameId = gameId;
    }

    public Integer getHostClubId() {
        return hostClubId;
    }

    public void setHostClubId(Integer hostClubId) {
        this.hostClubId = hostClubId;
    }

    public Integer getGuestClubId() {
        return guestClubId;
    }

    public void setGuestClubId(Integer guestClubId) {
        this.guestClubId = guestClubId;
    }

    public Integer getStadiumId() {
        return stadiumId;
    }

    public void setStadiumId(Integer stadiumId) {
        this.stadiumId = stadiumId;
    }

    public Integer getChampionshipId() {
        return championshipId;
    }

    public void setChampionshipId(Integer championshipId) {
        this.championshipId = championshipId;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setDate(LocalDate date) {
        this.date = java.sql.Date.valueOf(date);
    }

    public String getScore() {
        return score;
    }

    public void setScore(String score) {
        this.score = score;
    }

    @Override
    public String toString() {
        return "Game{" +
                "gameId=" + gameId +
                ", hostClubId=" + hostClubId +
                ", guestClubId=" + guestClubId +
                ", stadiumId=" + stadiumId +
                ", championshipId=" + championshipId +
                ", date=" + date +
                ", score='" + score + '\'' +
                '}';
    }
}
