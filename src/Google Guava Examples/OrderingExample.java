package src.Google_Guava_Practice;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import com.google.common.collect.Ordering;
import com.google.common.base.Preconditions;

class wine {
    //MEMBER VARIABLES
    private int Wine;
    private double Alcohol;
    private double Malic_acid;
    private double Ash;
    private double Acl;
    private int Mg;
    private double Phenols;
    private double Flavanoids;
    private double Nonflavanoid_phenols;
    private double Proanth;
    private double Color_int;
    private double Hue;
    private double OD;
    private double Proline;

    //CONSTRUCTORS
    public wine(){
        Wine = 0; Alcohol = 0; Malic_acid = 0; Ash = 0; Acl = 0; Mg = 0; Phenols = 0; Flavanoids = 0;
        Nonflavanoid_phenols = 0; Proanth = 0; Color_int = 0; Hue = 0; OD = 0; Proline = 0;
    }
    public wine(int newWine, double newAlcohol, double newMalic_acid, double newAsh, double newAcl, int newMg,
                double newPhenols, double newFlavanoids, double newNonflavanoid_phenols, double newProanth,
                double newColor_int, double newHue, double newOD, double newProline)
    {

        this.Wine = newWine; this.Alcohol = newAlcohol; this.Malic_acid = newMalic_acid; this.Ash = newAsh;
        this.Acl = newAcl; this.Mg = newMg; this.Phenols = newPhenols; this.Flavanoids = newFlavanoids;
        this.Nonflavanoid_phenols = newNonflavanoid_phenols; this.Proanth = newProanth; this.Color_int = newColor_int;
        this.Hue = newHue; this.OD = newOD; this.Proline = newProline;
    }

    //ACCESSORS
    public static Comparator<wine> alcoholComparator = (w1, w2) -> (int)(w1.Alcohol - w2.Alcohol);
    public static Comparator<wine> mgComparator = (w1, w2) -> w1.Mg - w2.Mg;

    public class OrderingExample {

    public static double round(double num, int n){
        try { Preconditions.checkArgument(n >= 0,"num must be rounded to nonzero n decimal places!"); }
        catch(IllegalArgumentException e) { e.printStackTrace(); return num; }
        return (double)Math.round(num * Math.pow(10, n)) / Math.pow(10, n);
    }

    public static void main(String[] args) {
        String csvFile = "./Datasets/wine.csv";
        FileReader fr;
        BufferedReader br = null;
        ArrayList<wine> wineArrayList = new ArrayList<>();
        try {
            fr = new FileReader(csvFile);
            br = new BufferedReader(fr);
            String line = "";
            String[] wineArray;
            while((line = br.readLine()) != null){
                wineArray = line.split(",");
                wineArrayList.add(new wine(
                        Integer.parseInt(wineArray[0]),
                        round(Double.parseDouble(wineArray[1]), 2),
                        round(Double.parseDouble(wineArray[2]), 2),
                        round(Double.parseDouble(wineArray[3]), 2),
                        round(Double.parseDouble(wineArray[4]), 1),
                        Integer.parseInt(wineArray[5]),
                        round(Double.parseDouble(wineArray[6]), 2),
                        round(Double.parseDouble(wineArray[7]), 2),
                        round(Double.parseDouble(wineArray[8]), 2),
                        round(Double.parseDouble(wineArray[9]), 2),
                        round(Double.parseDouble(wineArray[10]), 2),
                        round(Double.parseDouble(wineArray[11]), 2),
                        round(Double.parseDouble(wineArray[12]), 2),
                        Integer.parseInt(wineArray[13])
                        ));
            }

        } catch (FileNotFoundException e1){ e1.printStackTrace();
        } catch (IOException e2){ e2.printStackTrace();
        } finally { if(br != null) try { br.close(); } catch (IOException e){ e.printStackTrace(); } }


        Ordering<wine> wineOrdering = Ordering.from(wine.alcoholComparator).compound(wine.mgComparator).nullsFirst();
        Collections.sort(wineArrayList, wineOrdering.reverse());
    }


}