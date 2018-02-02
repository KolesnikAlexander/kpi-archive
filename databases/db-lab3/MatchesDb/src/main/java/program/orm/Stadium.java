package program.orm;

/**
 * Created by alex60070
 */
public class Stadium {
    Integer id;
    String name;
    String country;
    String city;
    Integer capacity;
    Boolean top_rated;
    String date;

    public Stadium() {}

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

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public Integer getCapacity() {
        return capacity;
    }

    public void setCapacity(Integer capacity) {
        this.capacity = capacity;
    }

    public Boolean getTop_rated() {
        return top_rated;
    }

    public void setTop_rated(Boolean top_rated) {
        this.top_rated = top_rated;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    @Override
    public String toString() {
        return "Stadium{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
