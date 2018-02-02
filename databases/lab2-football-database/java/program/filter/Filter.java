package program.filter;

/**
 * Created by alex60070
 */
public abstract class Filter {

    @Override
    public boolean equals(Object obj) {
       return this.getClass().equals((obj.getClass()));
    }
}
