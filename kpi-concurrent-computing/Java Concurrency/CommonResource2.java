import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by alex6 on 19.05.2017.
 */
public class CommonResource2 {
    private  int intValue;
    private  byte byteValue;
    private  float floatValue;
    private  long longValue;
    private  boolean boolValue;
    private  char charValue;

    public  ReentrantLock mutex = new ReentrantLock();

    public  void changeValues(){
        Set<Integer> used = new HashSet<>();
        int rand;
        for (int i = 0; i < 5; i++){
            do {
               rand = new Random().nextInt(6);
           } while (used.contains(rand));
            change(rand);
        }

    }

    private  void change(int rand) {
        //System.out.println("    "+Thread.currentThread().getName()+" changes");
        switch (rand){
            case 0:
                intValue = new Random().nextInt(100);
                break;
            case 1:
                byteValue = (byte) (new Random().nextInt(256) - 128);
                break;
            case 2:
                floatValue = new Random().nextFloat();
                break;
            case 3:
                longValue = new Random().nextLong();
                break;
            case 4:
                boolValue = new Random().nextBoolean();
                break;
            case 5:
                charValue = (char)(new Random().nextInt(20) + 'a');

            default:
                break;
        }
    }

    @Override
    public String toString() {
        return "CommonResource 2: " + "\n"+
                "   intValue = " + intValue + "\n" +
                "   byteValue = " + byteValue + "\n" +
                "   floatValue = " + floatValue +"\n" +
                "   longValue = " + longValue + "\n" +
                "   boolValue = " + boolValue + "\n" +
                "   charValue = " + charValue + "\n";
    }
}
