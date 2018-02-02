package program;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {


    @Override
    public void start(Stage primaryStage) throws Exception{
        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(Main.class.getResource("/res/main.fxml"));
        Parent root = loader.load();
        primaryStage.setTitle("DB Lab 2");
        primaryStage.setScene(new Scene(root, 1000, 750));
        primaryStage.show();

        Controller controller = loader.getController();
        controller.loadGameTable();

    }


    public static void main(String[] args) {
        launch(args);
    }
}
