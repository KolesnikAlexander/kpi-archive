package program.orm;

/**
 * Created by alex60070
 */
public class Club {
    Integer id;
    String name;
    String counry;
    String city;
    String coach;
    Boolean topRated;
    String estabDate;
    String description;

    public Club() {}

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCounry() {
        return counry;
    }

    public void setCounry(String counry) {
        this.counry = counry;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCoach() {
        return coach;
    }

    public void setCoach(String coach) {
        this.coach = coach;
    }

    public Boolean getTopRated() {
        return topRated;
    }

    public void setTopRated(Boolean topRated) {
        this.topRated = topRated;
    }

    public String getEstabDate() {
        return estabDate;
    }

    public void setEstabDate(String estabDate) {
        this.estabDate = estabDate;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    @Override
    public String toString() {
        return "Club{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
