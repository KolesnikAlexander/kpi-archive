package program.filter;

/**
 * Created by alex60070
 */
public class PhraseFilter extends Filter {
    String text;

    public PhraseFilter(String text) {
        this.text = text;
    }

    @Override
    public String toString() {
        return "PhraseFilter{" +
                "text='" + text + '\'' +
                '}';
    }
}
