package program;

import java.util.LinkedList;
import java.util.List;

/**
 * Created by alex60070
 */
public class Alg3 {
    private static List<Gasket> gaskets;
        public static void run() {
            if (gaskets == null) {
                gaskets = new LinkedList<>();
                gaskets.add(new Gasket(0, 0, 650));
            }
            else if (gaskets.isEmpty())
                return;

            Gasket gasket = gaskets.get(0);
            drawGasket(gasket.getX(), gasket.getY(), gasket.getSub());
            gaskets.remove(0);
        }

        private static void drawGasket(int x, int y, int side) {
            int sub = side / 3;
            MainView.drawRectangle(x + sub, y + sub, sub - 1, sub - 1);

            if (sub >= 3) {
                gaskets.add(new Gasket(x, y, sub));
                gaskets.add(new Gasket(x + sub, y, sub));
                gaskets.add(new Gasket(x + 2 * sub, y, sub));
                gaskets.add(new Gasket(x, y + sub, sub));
                gaskets.add(new Gasket(x + 2 * sub, y + sub, sub));
                gaskets.add(new Gasket(x, y + 2 * sub, sub));
                gaskets.add(new Gasket(x + sub, y + 2 * sub, sub));
                gaskets.add(new Gasket(x + 2 * sub, y + 2 * sub, sub));

                return;
            }
        }
}
