package BitManiputlation;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;
import java.util.stream.Collectors;


public final class BitUtils {
    //MEMBER FUNCTIONS
    /** Finds percentage of matching bits from LSB to MSB for 2 binary numbers
     * @param dec1 First base-10 integer to compare
     * @param dec2 Second base-10 integer to compare
     * @return Decimal equivalent to similarity ratio between base-2 versions of num1 and num2
     */
    public static double similarity(int dec1, int dec2){
        int match = 0;
        String s1 = Integer.toBinaryString(dec1), s2 = Integer.toBinaryString(dec2);
        for(int i = 1; i <= Math.min(s1.length(), s2.length()); i++)
            if(s1.charAt(s1.length() - i) == s2.charAt(s2.length() - i))
                ++match;
        return (double)match / Math.max(s1.length(), s2.length());
    }

    /** Computes the n^th magic number of a given base. A magic number of base <i>b</i> is any linear combination of
     * unique powers of <i>b</i>.
     * @param n Denotes n^th magic number, where n >= 1
     * @param base Specified base of magic number
     * @return n^th magic number using specified <code>base</code>
     */
    public static int magicNumber(int n, int base){
        if(n <= 0 || base <= 0)
            return -1;
        if(base == 1)
            return n;
        String s = Integer.toBinaryString(n);
        int output = 0, power = s.length() - 1;
        for(char c : Integer.toBinaryString(n).toCharArray()) {
            if (c == '1')
                output += Math.pow(base, power);
            --power;
        }
        return output;
    }

    /** Computes new base-10 integer by rotating its base-2 equivalent left or right specified number of shifts.
     * Note that MSB is always 1 in base-2 for this case.
     * @param dec Base-10 integer
     * @param rotate Number of shifts to the left (negative), right (positive) or no shifts (0) done to binary version of <code>dec</code>
     * @return New base-10 number that equals <code>dec</code> after rotating
     */
    public static int rotate(int dec, int rotate){
        String s = Integer.toBinaryString(dec);
        int output = dec, carryOver = 0, netRotate = rotate %  s.length();
        if(netRotate == 0)
            return dec;
        else if(netRotate < 0){
            for(int i = 0; i <= -netRotate - 1; i++)
                if(s.charAt(i) == '1'){
                    output -= Math.pow(2, s.length() - 1 - i);
                    carryOver += Math.pow(2, -netRotate - 1 - i);
                }
            output = output << -netRotate;
            output += carryOver;
        } else {
            for(int i = 0; i <= netRotate - 1; i++)
                if(s.charAt(s.length() - 1 - i) == '1'){
                    output -= Math.pow(2, i);
                    carryOver += Math.pow(2, s.length() - netRotate + i);
                }
            output = output >> netRotate;
            output += carryOver;
        }
        return output;
    }

    /** Swaps each bit of 2 to an even power with its immediate left bit, which is 2 to an odd power
     * @param dec Base-10 number
     * @return New base-10 number by swapping bits at even and odd powers of 2
     */
    public static int swapEvenOddBits(int dec){
        int absDec = Math.abs(dec);
        if(absDec == 0)
            return 1;
        if(absDec == 1)
            return 0;
        String s = Integer.toBinaryString(dec);
        int output = 0;
        int evenPowerBinary = IntStream.rangeClosed(0, (int)Math.ceil((double)s.length() / 2))
                .parallel()
                .boxed()
                .mapToInt(n -> (int)Math.pow(2, n * 2))
                .sum() | absDec;
        output = evenPowerBinary << 1;
        int oddPowerBinary = IntStream.rangeClosed(1, (int)Math.floor((double)s.length() / 2))
                .parallel()
                .boxed()
                .mapToInt(n -> (int)Math.pow(2, n * 2 - 1))
                .sum() | absDec;
        output += oddPowerBinary >> 1;
        return output;
    }

    /** Computes minimum number of flops needed for one base-10 integer to transform into another base-10 integer in
     * terms of base-2 number differences in bits
     * @param dec1 First base-10 number
     * @param dec2 Second base-10 number
     * @return Edit distance of 2 base-10 numbers in binary form
     */
    public static int editDistance(int dec1, int dec2){
        int xor = dec1 | dec2;
        return Collections.frequency(
                Integer.toBinaryString(xor)
                    .chars()
                    .parallel()
                    .map(n -> (char)n)
                    .boxed()
                    .collect(Collectors.toList()),
                '1');
    }

    /** Computes the next sparse number after <code>dec</code>. A sparse number in binary form has no 2 adjacent 1-bits.
     * @param dec Base-10 integer
     * @return Next closest sparse number
     */
    public static int nextSparseNumber(int dec){ return -1; }

    public static void main(String[] args){


    }
}
