package program.filter;

/**
 * Created by alex60070
 */
public class WordsPresentFilter extends Filter {
    String text;

    public WordsPresentFilter(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }

    @Override
    public String toString() {
        return "WordsPresentFilter{" +
                "text='" + text + '\'' +
                '}';
    }
}
