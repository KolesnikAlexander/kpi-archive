package program;

import javafx.concurrent.Task;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import static java.lang.Math.sqrt;

/**
 * Created by alex60070
 */
public class Alg1{

    private static List<Point> points = new LinkedList<>();

    public static void run() {
        points.add(new Point(10,PixelsArray.HEIGHT / 2 ));
        points.add(new Point( PixelsArray.WIDTH -10,PixelsArray.HEIGHT / 2 ));
        iteration();
    }

    public static void iteration(){
        LinkedList<Point> newPoints = new LinkedList<>();
        for (int i = 0; i < Alg1.points.size()-1; i++){
            List<Point> fractPoints = fractalLine(Alg1.points.get(i), Alg1.points.get(i+1));
            for (Point p:fractPoints){
                newPoints.addLast(p);
            }
        }
        points = newPoints;
        System.out.println("NUM OF DOTS:"+ Alg1.points.size());
        MainView.clearLines();
        drawLines();
    }

    private static void drawLines(){

        Iterator<Point> iterator = points.iterator();

        Point point0 = points.get(0);
        while (iterator.hasNext()){
            Point point1 = iterator.next();
            MainView.drawLine(point0.getX(),
                    point0.getY(),
                    point1.getX(),
                    point1.getY() );
            point0 = point1;
        }
    }

    private static List<Point> fractalLine(Point point0, Point point1){
        Point d0;
        Point d1;
        Point d2;
        int x0 = point0.getX();
        int y0 =point0.getY();
        int x1 = point1.getX();
        int y1 = point1.getY();

        int a = y1-y0;
        int b = x1-x0;

        double c = sqrt(a*a + b*b);

        double cosPhi = b/c;
        double sinPhi = a/c;

        double c1 = c/3;
        double c2 = (2*c)/3;

        MainView.drawPixel((int)c1, 20);
        MainView.drawPixel((int)c2+20, 10);

        double m = (c1 + c2)/2;
        double l = c2 - c1;
        double h = sqrt(3)/2*l;

        d0 = new Point((int)m,(int) -h);
        d1 = new Point((int)c1, 0);
        d2 = new Point((int)c2, 0);

        d0 = turn(sinPhi,cosPhi, d0);
        d1 = turn(sinPhi,cosPhi, d1);
        d2 = turn(sinPhi,cosPhi, d2);

        d0 = shift(x0, y0, d0);
        d1 = shift(x0, y0, d1);
        d2 = shift(x0, y0, d2);

        LinkedList<Point> points = new LinkedList<>();

        points.add(point0);
        points.add(d1);
        points.addLast(d0);
        points.addLast(d2);
        points.addLast(point1);
        return points;
    }

    private static Point turn(double sin, double cos, Point point){
        int newX = (int)(point.getX()*cos - point.getY()*sin);
        int newY = (int)(point.getX()*sin + point.getY()*cos);
        return new Point(newX, newY);
    }

    private static Point shift(int x, int y, Point point){
        int newX = point.getX() + x;
        int newY = point.getY() + y;
        return new Point(newX, newY);
    }


}
