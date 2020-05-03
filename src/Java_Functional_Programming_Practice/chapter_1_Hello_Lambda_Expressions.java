
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.math.BigDecimal;

public class chapter_1_Hello_Lambda_Expressions {
    public static void main(String[] args) {
        //Search for item in ArrayList
        // OLD WAY: using range-based for loop
        ArrayList<String> cities = new ArrayList<String>(
            Arrays.asList(
                "Moscow",
                "Beijing",
                "Seoul",
                "Tokyo",
                "Houston",
                "Chicago",
                "Toronto",
                "Zurich",
                "Milan"
            )
        );

        boolean found = false;
        for(String city : cities) {
            if(city == "Chicago") {
                found = true;
                break;
            }
        }

        System.out.println("Found Chicago? " + found);

        //NEW WAY: use contains
        found = cities.contains("Chicago");
        System.out.println("Found Chicago? " + found);

        //Find and transform certain elements of collection based on criteria
        //Example: Find all prices > 20 and take 10% discount off the sum
        //OLD WAY: manually accumulate
        final List<BigDecimal> prices = Arrays.asList(
                new BigDecimal("10"),
                new BigDecimal("30"),
                new BigDecimal("17"),
                new BigDecimal("20"),
                new BigDecimal("15"),
                new BigDecimal("18"),
                new BigDecimal("45"),
                new BigDecimal("12")
        );

        BigDecimal total = BigDecimal.ZERO;
        for(BigDecimal price : prices) {
            if(price.compareTo(BigDecimal.valueOf(20)) > 0) {
                total = BigDecimal(total.intval() + price.intval());
            }
        }
        total = total.multiply(0.90);

        System.out.println("Discounted price: " + total.doubleval());

        //NEW WAY: use stream
        total = prices.stream()
                .filter(p.compareTo(BigDecimal.valueOf(20)) > 0)
                .map(p -> p.multiply(0.9))
                .reduce(BigDecimal.ZERO, BigDecimal::add);

        System.out.println("Discounted price: " + total.doubleval());
    }
}

