package program;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import program.dao.GamesDao;
import program.entity.GameEntity;
import program.filter.*;


/**
 * Created by alex60070
 */
public class Model {
    public static ObservableList<GameEntity> games = FXCollections.observableArrayList();

    //Temporary
    static {
        games.add(createGame());
    }

    public static ObservableList<GameEntity> readGameTable(Filter filter){
        System.out.println("READ| Filter:"+filter);//<------------------------------------
        if (filter.equals(new NoFilter())){
            return GamesDao.readNoFilter();
        }
        else if (filter.equals(new TopRatedFilter(Entity.CHAMPIONSHIP))){
            return GamesDao.championshipTopRated();
        }
        else if (filter.equals(new TopRatedFilter(Entity.CLUB))){
            return GamesDao.clubTopRated();
        }
        else if (filter.equals(new TopRatedFilter(Entity.STADIUM))){
            return GamesDao.stadiumTopRated();
        }
        else if (filter.equals(new EstabDateFilter(Entity.CHAMPIONSHIP,0,0))){
            EstabDateFilter estDateFilt = (EstabDateFilter) filter;
            return GamesDao.championshipEstabDate(estDateFilt.getFrom(), estDateFilt.getTo());
        }
        else if (filter.equals(new EstabDateFilter(Entity.CLUB,0,0))){
            EstabDateFilter estDateFilt = (EstabDateFilter) filter;
            return GamesDao.clubEstabDate(estDateFilt.getFrom(), estDateFilt.getTo());
        }
        else if (filter.equals(new EstabDateFilter(Entity.STADIUM,0,0))){
            EstabDateFilter estDateFilt = (EstabDateFilter) filter;
            return GamesDao.stadiumEstabDate(estDateFilt.getFrom(), estDateFilt.getTo());
        }
        else if (filter.equals(new WordsPresentFilter(""))){
            WordsPresentFilter fil = (WordsPresentFilter) filter;
            return GamesDao.wordsSearch(fil.getText());
        }
        else
            return null;
    }

    public static GameEntity createGame(){

        GameEntity game = new GameEntity();
        game.setGameId(5);
        game.setHostClub("Shakhtar");
        game.setGuestClub("Dinamo");
        game.setStadium("Donbass Arena");
        game.setChampionship("UA Premier League");
        game.setScore("5-0");
        game.setDate(1111, 9, 5);
        return game;
    }
}
