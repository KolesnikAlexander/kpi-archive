package program.orm;

/**
 * Created by alex60070
 */
public class Championship {
    Integer id;
    String name;
    String season;
    String federation;
    Boolean topRated;
    String estabDate;

    public Championship() {}

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

    public String getSeason() {
        return season;
    }

    public void setSeason(String season) {
        this.season = season;
    }

    public String getFederation() {
        return federation;
    }

    public void setFederation(String federation) {
        this.federation = federation;
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

    @Override
    public String toString() {
        return "Championship{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}
