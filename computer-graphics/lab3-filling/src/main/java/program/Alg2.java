package program;

import javafx.concurrent.Task;

import java.util.*;

/**
 * Created by alex60070
 */
public class Alg2 extends Task<Void> {
    List<Pixel> pixels = new LinkedList<>();
    int countLines = 0;
    private static Set<Pixel> vertexes = new HashSet<>();
    @Override
    public Void call() throws Exception {

        int count = 0;
        for (int i = 0; i < PixelsArray.HEIGHT; i++){
            for (Line line : PixelsArray.borders) {
                int x = getXFromLineEquation(i, line);
                if (x != -1){
                    pixels.add(new Pixel(x, i));
//                    System.out.println("WORKED");
//                    MainView.bresenhamLine(x, i, x + 100, i);
//                    count++;
                }
            }
            Collections.sort(pixels, new Comparator<Pixel>() {
                @Override
                public int compare(Pixel o1, Pixel o2) {
                    return o1.getX() - o2.getX();
                }
            });
            System.out.println("YO3!");

            if (pixels.size() % 2 != 0)
            pixels.remove(pixels.size() - 1);

            drawLines();
            System.out.println("Last count lines:" + countLines);
            pixels = new LinkedList<>();
        }

        System.out.println("COUNT: "+count);

        return null;
    }

    private void drawLines() {
        Iterator<Pixel> iterator = pixels.iterator();

        while (iterator.hasNext()){
            Pixel first = iterator.next();
            Pixel second = null;
            try {
                second = iterator.next();
            }catch (Exception e) {
                System.out.println("OLOLO"+e);
            }
            System.out.println("YO6.2");
            MainView.bresenhamLine(first.getX(), first.getY(),
                    second.getX(),second.getY());
        }
    }

    private static int getXFromLineEquation(int y, Line line){
        if(y == line.getStartY()) {
            Line prevLine;

            int id = PixelsArray.borders.indexOf(line);
            if (id == 0)
                prevLine = PixelsArray.borders.get(PixelsArray.borders.size() - 1);
            else
                 prevLine = PixelsArray.borders.get(id - 1);

            if ((line.getEndY() < line.getStartY() && prevLine.getStartY() < line.getStartY()) ||
                    (line.getEndY() > line.getStartY() && prevLine.getStartY() > line.getStartY()))
            {
                return -1;
            }
        }
        if(y == line.getEndY()) {
            Line nextLine;

            int id = PixelsArray.borders.indexOf(line);
            if (id == PixelsArray.borders.size() - 1)
                nextLine = PixelsArray.borders.get(0);
            else
                nextLine = PixelsArray.borders.get(id + 1);

            if ((line.getEndY() < line.getStartY() && line.getEndY() < nextLine.getEndY()) ||
                    (line.getEndY() > line.getStartY() && line.getEndY() > nextLine.getEndY())) {
                return -1;
            }
        }

//Second part
        if (y == line.getStartY()){
            if (vertexes.contains(new Pixel(line.getStartX(), line.getStartY())))
                return -1;
            else{
                vertexes.add(new Pixel(line.getStartX(), line.getStartY()));
                return line.getStartX();
            }
        }

        else if (y == line.getEndY()){
            if (vertexes.contains(new Pixel(line.getEndX(), line.getEndY())))
                return -1;
            else{
                vertexes.add(new Pixel(line.getEndX(), line.getEndY()));
                return line.getEndX();
            }
        }
//            return line.getEndX();
         if (!(
                ((y >= line.getStartY()) && (y <= line.getEndY())) ||
                ((y <= line.getStartY()) && (y >= line.getEndY()))
        ))
            return -1;
        int x1 = line.getStartX();
        int y1 = line.getStartY();
        int x2 = line.getEndX();
        int y2 = line.getEndY();

        double numerator = (x2-x1)*(y-y1);
        double denominator = y2-y1;
        return (int)(numerator/denominator + x1);
    }

}


