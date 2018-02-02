package program;

import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Modality;
import javafx.stage.Stage;
import program.dao.GamesDao;
import program.entity.GameEntity;
import program.filter.*;

import java.io.IOException;
import java.net.URL;
import java.time.LocalDate;
import java.util.ResourceBundle;


public class Controller implements Initializable {

    public static Parent root;
    public static Stage addUpdateStage;
    public static Scene addUpdateScene;


    ToggleGroup filtersToggleGroup = new ToggleGroup();

    @FXML
    TableView<GameEntity> gamesTable;
    @FXML
    TableColumn<GameEntity, String> hostColumn;
    @FXML
    TableColumn<GameEntity, String> guestColumn;
    @FXML
    TableColumn<GameEntity, String> stadiumColumn;
    @FXML
    TableColumn<GameEntity, String> championshipColumn;
    @FXML
    TableColumn<GameEntity, String> scoreColumn;
    @FXML
    TableColumn<GameEntity, LocalDate> dateColumn;


    @FXML
    public RadioButton noFilter;


    @FXML
    public RadioButton champTopRated;
    @FXML
    public RadioButton champEstabDate;
    @FXML
    public Slider champEstabDateSlider;


    @FXML
    public RadioButton clubTopRated;
    @FXML
    public RadioButton clubEstabDate;
    @FXML
    public Slider clubEstabDateSlider;
    @FXML
    public RadioButton wordsPresent;
    @FXML
    public TextField wordsPresentTextField;
    @FXML
    public RadioButton wholePhrase;
    @FXML
    public TextField wholePhraseTextField;


    @FXML
    public RadioButton stadiumTopRated;
    @FXML
    public RadioButton stadiumEstabDate;
    @FXML
    public Slider stadiumEstabDateSlider;


    @FXML
    public Button applyButton;


    @Override
    public void initialize(URL location, ResourceBundle resources) {
        initTable();
        initRadioButtons();
    }

    private void initRadioButtons() {
        noFilter.setToggleGroup(filtersToggleGroup);
        noFilter.setUserData("noFilter");

        champTopRated.setToggleGroup(filtersToggleGroup);
        champTopRated.setUserData("champTopRated");
        champEstabDate.setToggleGroup(filtersToggleGroup);
        champEstabDate.setUserData("champEstabDate");

        clubTopRated.setToggleGroup(filtersToggleGroup);
        clubTopRated.setUserData("clubTopRated");
        clubEstabDate.setToggleGroup(filtersToggleGroup);
        clubEstabDate.setUserData("clubEstabDate");
        wordsPresent.setToggleGroup(filtersToggleGroup);
        wordsPresent.setUserData("wordsPresent");
        wholePhrase.setToggleGroup(filtersToggleGroup);
        wholePhrase.setUserData("wholePhrase");
        stadiumTopRated.setToggleGroup(filtersToggleGroup);
        stadiumTopRated.setUserData("stadiumTopRated");
        stadiumEstabDate.setToggleGroup(filtersToggleGroup);
        stadiumEstabDate.setUserData("championshipEstabDate");

    }

    private void initTable(){
        hostColumn.setCellValueFactory(cellData -> cellData.getValue().hostClubProperty());
        guestColumn.setCellValueFactory(cellData -> cellData.getValue().guestClubProperty());
        stadiumColumn.setCellValueFactory(cellData -> cellData.getValue().stadiumProperty());
        championshipColumn.setCellValueFactory(cellData -> cellData.getValue().championshipProperty());
        scoreColumn.setCellValueFactory(cellData -> cellData.getValue().scoreProperty());
        dateColumn.setCellValueFactory(cellData -> cellData.getValue().dateProperty());
    }

    //Called after the stage is shown
    public void loadGameTable(){
        ObservableList<GameEntity> gameEntities = Model.readGameTable(new NoFilter());
        fillGamesTable(gameEntities);
    }

    @FXML
    public void onApplyButtonClicked(MouseEvent event) {
        String selectedFilter = (String) filtersToggleGroup.getSelectedToggle().getUserData();
        Filter filter = null;

        if (selectedFilter.equals("noFilter"))
            filter = new NoFilter();

        else if (selectedFilter.equals("champTopRated"))
            filter = new TopRatedFilter(Entity.CHAMPIONSHIP);

        else if (selectedFilter.equals("clubTopRated"))
            filter = new TopRatedFilter(Entity.CLUB);

        else if (selectedFilter.equals("stadiumTopRated"))
            filter = new TopRatedFilter(Entity.STADIUM);

        else if (selectedFilter.equals("champEstabDate")){
            int from = (int) champEstabDateSlider.getValue();
            int to = 2100;
            filter = new EstabDateFilter(Entity.CHAMPIONSHIP, from, to);
        }
        else if (selectedFilter.equals("clubEstabDate")){
            int from = (int) clubEstabDateSlider.getValue();
            int to = 2100;
            filter = new EstabDateFilter(Entity.CLUB, from, to);
        }
        else if (selectedFilter.equals("championshipEstabDate")){
            int from = (int) stadiumEstabDateSlider.getValue();
            int to = 2100;
            filter = new EstabDateFilter(Entity.STADIUM, from, to);
        }
        else if (selectedFilter.equals("wordsPresent")){
            filter = new WordsPresentFilter(wordsPresentTextField.getText());
        }
        else if (selectedFilter.equals("wholePhrase")){
            filter = new PhraseFilter(wholePhraseTextField.getText());
        }

        ObservableList<GameEntity> gameEntities = Model.readGameTable(filter);
        fillGamesTable(gameEntities);
    }

    @FXML
    public void addButtonClicked(MouseEvent event) {

        try {

            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(this.getClass().getClassLoader().getResource("res/addUpdate.fxml"));
            root = loader.load();

            addUpdateStage = new Stage();
            addUpdateStage.setTitle("Add item");
            addUpdateStage.initModality(Modality.APPLICATION_MODAL);
            addUpdateScene = new Scene(root);

            addUpdateStage.setScene(addUpdateScene);

            AddUpdateController controller = loader.<AddUpdateController>getController();
            controller.setUpdate(false);
            controller.setGameToUpdate(null);
            controller.start();

            addUpdateStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @FXML
    public void editButtonClicked(MouseEvent event) {
        GameEntity selectedItem = gamesTable.getSelectionModel().getSelectedItem();
        if (selectedItem == null){
            Alert alert = new Alert(Alert.AlertType.WARNING,"Select item");
            alert.showAndWait();
            return;
        }
        try {

            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(this.getClass().getClassLoader().getResource("res/addUpdate.fxml"));
            root = loader.load();

            addUpdateStage = new Stage();
            addUpdateStage.setTitle("Update item");
            addUpdateStage.initModality(Modality.APPLICATION_MODAL);
            addUpdateScene = new Scene(root);

            addUpdateStage.setScene(addUpdateScene);

            AddUpdateController controller = loader.<AddUpdateController>getController();
            controller.setUpdate(true);
            controller.setGameToUpdate(gamesTable.getSelectionModel().getSelectedItem());
            controller.start();

            addUpdateStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    // VIEW

    private void fillGamesTable(ObservableList<GameEntity> gameEntities){
        gamesTable.setItems(gameEntities);
    }

    @FXML
    public void delButtonClicked(MouseEvent event) {
        GameEntity selectedItem = gamesTable.getSelectionModel().getSelectedItem();
        if (selectedItem == null){
            Alert alert = new Alert(Alert.AlertType.WARNING,"Select item");
            alert.showAndWait();
            return;
        }
        else {
            if(GamesDao.deleteGame(selectedItem)){
                Alert alert = new Alert(Alert.AlertType.INFORMATION,"Successfully deleted");
                alert.showAndWait();
            }
            else {
                Alert alert = new Alert(Alert.AlertType.ERROR,"Cannot delete data");
                alert.showAndWait();
            }
        }
    }
}