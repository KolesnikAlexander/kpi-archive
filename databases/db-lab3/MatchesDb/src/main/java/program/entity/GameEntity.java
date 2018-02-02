package program.entity;

import javafx.beans.property.*;

import java.time.LocalDate;

/**
 * Created by alex60070
 */
public class GameEntity {
        private IntegerProperty gameId;
        private StringProperty hostClub;
        private StringProperty guestClub;
        private StringProperty stadium;
        private StringProperty championship;
        private StringProperty score;
        private ObjectProperty<LocalDate> date;

        private int hostClubId;
        private int guestClubId;
        private int stadiumId;
        private int championshipId;


    public GameEntity() {
        this.gameId = new SimpleIntegerProperty();
        this.hostClub = new SimpleStringProperty();
        this.guestClub = new SimpleStringProperty();
        this.stadium = new SimpleStringProperty();
        this.championship = new SimpleStringProperty();
        this.score = new SimpleStringProperty();
        this.date = new SimpleObjectProperty<>();

    }

    public int getGameId() {
        return gameId.get();
    }

    public IntegerProperty gameIdProperty() {
        return gameId;
    }

    public void setGameId(int gameId) {
        this.gameId.set(gameId);
    }

    public String getHostClub() {
        return hostClub.get();
    }

    public StringProperty hostClubProperty() {
        return hostClub;
    }

    public void setHostClub(String hostClub) {
        this.hostClub.set(hostClub);
    }

    public String getGuestClub() {
        return guestClub.get();
    }

    public StringProperty guestClubProperty() {
        return guestClub;
    }

    public void setGuestClub(String guestClub) {
        this.guestClub.set(guestClub);
    }

    public String getStadium() {
        return stadium.get();
    }

    public StringProperty stadiumProperty() {
        return stadium;
    }

    public void setStadium(String stadium) {
        this.stadium.set(stadium);
    }

    public String getChampionship() {
        return championship.get();
    }

    public StringProperty championshipProperty() {
        return championship;
    }

    public void setChampionship(String championship) {
        this.championship.set(championship);
    }

    public String getScore() {
        return score.get();
    }

    public StringProperty scoreProperty() {
        return score;
    }

    public void setScore(String score) {
        this.score.set(score);
    }

    public LocalDate getDate() {
        return date.get();
    }

    public ObjectProperty<LocalDate> dateProperty() {
        return date;
    }

    public void setDate(int year, int month, int day) {
        LocalDate date = LocalDate.of(year, month, day);
        this.date.set(date);
    }

    public int getHostClubId() {
        return hostClubId;
    }

    public void setHostClubId(int hostClubId) {
        this.hostClubId = hostClubId;
    }

    public int getGuestClubId() {
        return guestClubId;
    }

    public void setGuestClubId(int guestClubId) {
        this.guestClubId = guestClubId;
    }

    public int getStadiumId() {
        return stadiumId;
    }

    public void setStadiumId(int stadiumId) {
        this.stadiumId = stadiumId;
    }

    public int getChampionshipId() {
        return championshipId;
    }

    public void setChampionshipId(int championshipId) {
        this.championshipId = championshipId;
    }
}


