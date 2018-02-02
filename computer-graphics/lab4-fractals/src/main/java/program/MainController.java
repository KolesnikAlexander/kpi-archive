package program;

import javafx.fxml.Initializable;
import javafx.scene.input.KeyCode;
import javafx.scene.input.MouseEvent;
import java.net.URL;
import java.util.ResourceBundle;

/**
 * Created by alex60070
 */
public class MainController implements Initializable{


    @Override
    public void initialize(URL location, ResourceBundle resources) {

    }
    public static void keyPressed(KeyCode key) {
        MainModel.keyPressed(key);
    }

}
