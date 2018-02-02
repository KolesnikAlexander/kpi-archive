package program.filter;

import program.Entity;

/**
 * Created by alex60070
 */
public class TopRatedFilter extends Filter {
    Entity entity;

    public TopRatedFilter(Entity entity) {
        this.entity = entity;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj) &&
                this.entity == ((TopRatedFilter) obj).entity;
    }

    @Override
    public String toString() {
        return "TopRatedFilter{" +
                "entity=" + entity +
                '}';
    }
}
