package program.filter;

import program.Entity;

/**
 * Created by alex60070
 */
public class EstabDateFilter extends Filter {
    Entity entity;
    int from;
    int to;

    public EstabDateFilter(Entity entity, int from, int to) {
        this.entity = Entity.CHAMPIONSHIP;
        this.from = from;
        this.to = to;
    }

    public int getFrom() {
        return from;
    }

    public int getTo() {
        return to;
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj) &&
                this.entity == ((EstabDateFilter) obj).entity;
    }

    @Override
    public String toString() {
        return "EstabDateFilter{" +
                "from=" + from +
                ", to=" + to +
                '}';
    }
}
