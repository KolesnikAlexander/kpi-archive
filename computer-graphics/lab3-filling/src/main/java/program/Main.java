package program;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.WritableImage;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application {
    public static Pane root;
    public static Scene mainScene;
    public static Canvas canvas;
    public static ImageView imgView;

    @Override
    public void start(Stage primaryStage) throws Exception{
        canvas = new Canvas(850, 650);
        canvas.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                MainController.canvasClick(event);
            }
        });

        root = FXMLLoader.load(getClass().getResource("/res/main.fxml"));
        root.getChildren().add(canvas);



        Scene scene = new Scene(root, 850, 650);
        scene.setOnKeyPressed(e -> {
            MainController.keyPressed(e.getCode());
        });

        primaryStage.setTitle("Lab 1 - DDA line algorithm");
        primaryStage.setResizable(false);
        primaryStage.setScene(scene);
        primaryStage.show();

        mainScene = primaryStage.getScene();
        MainModel.start();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
