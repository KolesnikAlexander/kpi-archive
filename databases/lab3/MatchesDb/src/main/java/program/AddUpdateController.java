package program;

import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.util.StringConverter;
import program.dao.DimentionsDao;
import program.dao.GamesDao;
import program.entity.DimentionEntity;
import program.entity.GameEntity;

import java.net.URL;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.ResourceBundle;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by alex60070
 */
public class AddUpdateController implements Initializable{

    @FXML
    public ComboBox hostComboBox;

    @FXML
    public ComboBox guestComboBox;

    @FXML
    public ComboBox stadiumComboBox;

    @FXML
    public ComboBox champComboBox;

    @FXML
    public DatePicker datePicker;

    @FXML
    public TextField scoreLeft;

    @FXML
    public TextField scoreRight;

    private Boolean update;
    private GameEntity gameToUpdate;



    public Boolean getUpdate() {
        return update;
    }

    public void setUpdate(Boolean update) {
        this.update = update;
    }

    public GameEntity getGameToUpdate() {
        return gameToUpdate;
    }

    public void setGameToUpdate(GameEntity gameToUpdate) {
        this.gameToUpdate = gameToUpdate;
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        setDateFormat();
    }


    @FXML
    public void okButtonClicked(MouseEvent event) {
        if (!update) {
            insertProcess();
        }

        else{
            updateProcess();
        }
    }

    public void start() {
        loadComboBoxes();
        if (update)
            setDataToStage(gameToUpdate);
    }

    private void insertProcess() {
//        ObservableList<GameEntity> gameEntities = GamesDao.readNoFilter();
        GameEntity gameEntity = takeDataFromStage();

        if(GamesDao.insertGame(gameEntity)){
            Alert alert = new Alert(Alert.AlertType.INFORMATION,"Successfully inserted");
            alert.showAndWait();
        }
        else {
            Alert alert = new Alert(Alert.AlertType.ERROR,"Cannot insert data");
            alert.showAndWait();
        }
    }

    private void updateProcess() {
        GameEntity gameEntity = takeDataFromStage();
        gameEntity.setGameId(gameToUpdate.getGameId());
        if(GamesDao.updateGame(gameEntity)){
            Alert alert = new Alert(Alert.AlertType.INFORMATION,"Successfully updated");
            alert.showAndWait();
        }
        else {
            Alert alert = new Alert(Alert.AlertType.ERROR,"Cannot update data");
            alert.showAndWait();
        }
    }

    private GameEntity takeDataFromStage() {
        ((DimentionEntity)champComboBox.getSelectionModel().getSelectedItem()).getId();
        int championshipId =  ((DimentionEntity)champComboBox.getSelectionModel().getSelectedItem()).getId();
        int stadiumId =  ((DimentionEntity)stadiumComboBox.getSelectionModel().getSelectedItem()).getId();
        int hostClubId =  ((DimentionEntity)hostComboBox.getSelectionModel().getSelectedItem()).getId();
        int guestClubId =  ((DimentionEntity)guestComboBox.getSelectionModel().getSelectedItem()).getId();
        LocalDate date = datePicker.getValue();
        int year = date.getYear();
        int month = date.getMonthValue();
        int day = date.getDayOfMonth();
        String score = scoreLeft.getText()+"-"+scoreRight.getText();

        GameEntity gameEntity = new GameEntity();

        gameEntity.setChampionshipId(championshipId);
        gameEntity.setStadiumId(stadiumId);
        gameEntity.setHostClubId(hostClubId);
        gameEntity.setGuestClubId(guestClubId);
        gameEntity.setDate(year, month, day);
        gameEntity.setScore(score);

        return gameEntity;
    }



    private void loadComboBoxes() {
        ObservableList<DimentionEntity> clubs = DimentionsDao.readClubs();
        hostComboBox.setItems(clubs);
        guestComboBox.setItems(clubs);
        stadiumComboBox.setItems(DimentionsDao.readStadiums());
        champComboBox.setItems(DimentionsDao.readChampionships());
    }

    private void setDateFormat() {
        datePicker.setConverter(new StringConverter<LocalDate>() {
            String pattern = "yyyy-MM-dd";
            DateTimeFormatter dateFormatter = DateTimeFormatter.ofPattern(pattern);

            {
                datePicker.setPromptText(pattern.toLowerCase());
            }

            @Override public String toString(LocalDate date) {
                if (date != null) {
                    return dateFormatter.format(date);
                } else {
                    return "";
                }
            }

            @Override public LocalDate fromString(String string) {
                if (string != null && !string.isEmpty()) {
                    return LocalDate.parse(string, dateFormatter);
                } else {
                    return null;
                }
            }
        });
    }

    public void setDataToStage(GameEntity game) {
        champComboBox.getSelectionModel().select(new DimentionEntity("nop", game.getChampionshipId()));
        stadiumComboBox.getSelectionModel().select(new DimentionEntity("nop", game.getStadiumId()));
        hostComboBox.getSelectionModel().select(new DimentionEntity("nop", game.getHostClubId()));
        guestComboBox.getSelectionModel().select(new DimentionEntity("nop", game.getGuestClubId()));
        datePicker.setValue(game.getDate());
        ArrayList<Integer> splitScore = splitScore(game.getScore());
        scoreLeft.setText(splitScore.get(0).toString());
        scoreRight.setText(splitScore.get(1).toString());
    }
    public static ArrayList<Integer> splitScore(String date) {

        Pattern usrIdPattern = Pattern.compile("^(.*)-(.*)$",
                Pattern.CASE_INSENSITIVE);
        Matcher matcher = usrIdPattern.matcher(date);

        if(!matcher.find()){
            System.out.println("Cannot parse date");
            return null;
        }
        int left = Integer.parseInt(matcher.group(1));
        int right = Integer.parseInt(matcher.group(2));

        ArrayList<Integer> integers = new ArrayList<>(2);
        integers.add(left);
        integers.add(right);

        return integers;
    }
}