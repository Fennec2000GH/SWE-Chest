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
        String xorString = Integer.toBinaryString(dec1 ^ dec2);
        //mismatches are signaled by having a 1 at the position in xorString
        for(char c : xorString.toCharArray())
            if(c == '1')
                ++match;
        int dec1Length = (int)Math.floor(Math.log(dec1) / Math.log(2)) + 1,
            dec2Length = (int)Math.floor(Math.log(dec2) / Math.log(2)) + 1;
        return (double)match / Math.max(dec1Length, dec2Length);
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
     * Note that MSB is always 1 in base-2 for this case, and only magnitude is considered, so sign stays the same.
     * @param dec Base-10 integer
     * @param rotate Number of shifts to the left (negative), right (positive) or no shifts (0) done to binary version of <code>dec</code>
     * @return New base-10 number that equals <code>dec</code> after rotating
     */
    public static int rotate(int dec, int rotate){
        String s = Integer.toBinaryString(dec);
        int output = Math.abs(dec), //output initialized to absolute value of dec
            carryOver = 0, //bits that fall off the edge during rotation are re-added at the opposite end of number
            netRotate = Math.abs(rotate) %  s.length(); //absolute number of shifts in either direction relative to binary string
        //nothing changed
        if(dec == 0)
            return 0;
        if(rotate == 0)
            return dec;
        //left rotation by 1 or more bits
        else if(rotate < 0){
            for(int i = 0; i <= netRotate - 1; i++)
                if(s.charAt(i) == '1'){
                    output -= Math.pow(2, s.length() - 1 - i);
                    carryOver += Math.pow(2, netRotate - 1 - i);
                }
            output <<= netRotate;
            output += carryOver;
        //right rotation by 1 or more bits
        } else {
            for(int i = 0; i <= netRotate - 1; i++)
                if(s.charAt(s.length() - 1 - i) == '1')
                    carryOver += Math.pow(2, s.length() - netRotate + i);
            output >>=  netRotate;
            output += carryOver ;
        }
        output *= Math.signum(rotate);
        return output;
    }

    /** Rotates base-2 version of given <code>BigInteger</code>.
     * @param dec A given <code>BigInteger</code>
     * @param rotate Number of shifts to the left (negative), right (positive) or no shifts (0) done to binary version of <code>dec</code>
     * @return New base-10 <code>BigInteger</code> that equals <code>dec</code> after rotating
     */
    public static BigInteger rotateBigInteger(BigInteger dec, long rotate){
        try {
            String s = Long.toBinaryString(dec.longValueExact());
            long netRotate = Math.abs(rotate) % s.length();
            //nothing changed
            if(dec.longValueExact() == 0)
                return BigInteger.ZERO;
            if(rotate == 0)
                return BigInteger.valueOf(dec.longValueExact());
            if(netRotate > s.length() / 2)
                return BigInteger.valueOf(BitUtils.rotate(dec.intValueExact(), -(int)(s.length() - netRotate)));
            return BigInteger.valueOf(BitUtils.rotate(dec.intValueExact(), (int)netRotate) * Long.signum(rotate));
        } catch (ArithmeticException e) {
            return null;
        }
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
        int output;
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
        return Integer.signum(dec) * output;
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
     * @return Whether <code>dec</code> is a sparse number or not
     */
    public static boolean isSparse(int dec){
        int absDec = Math.abs(dec);
        while(absDec > 0) {
            //right shifts absDec until LSB is 1
            while(absDec % 2 == 0)
                absDec >>= 1;
            absDec >>= 1; //finds next digit left of current LSB
            if(absDec % 2 == 1) //absDec still odd implies next LSB is still 1 and did not change
                return false;
        }
        return true;
    }

    /** Computes the next sparse number after <code>dec</code>. A sparse number in binary form has no 2 adjacent 1-bits.
     * Credit to <i>kk_angel</i>.
     * @param dec Base-10 integer
     * @return Next closest sparse number
     */
    public static int nextSparseNumber(int dec){
        StringBuilder sb = new StringBuilder(Integer.toBinaryString(dec));
        char[] trailingZeroes;
        //index in StringBuilder at the last occurrence of adjacent 1's
        int zeroIndex;
        //edge cases
        if(dec < 0)
            return -1;
        if(dec == 0)
            return 1;
        //dec is 111111...111, so the next sparse number is 10000...000 with length elongated by 1
        if(sb.lastIndexOf("0") == -1)
            return dec + 1;
        if(BitUtils.isSparse(dec)) {
            int index001 = sb.lastIndexOf("001");
            if (index001 >= 1) {
                sb.setCharAt(index001 + 1, '1');
                trailingZeroes = new char[sb.length() - index001 - 1];
                Arrays.fill(trailingZeroes, '0');
                sb.replace(index001 + 2, sb.length(), String.valueOf(trailingZeroes));
                return Integer.parseInt(sb.toString(), 2);
            } else //dec is 1010101...101
                return (int) Math.pow(2, sb.length());
        }
        //initial 2 bits are both 1's, meaning dec is 11...
        if(sb.substring(0, 2).equals("11"))
            return (int) Math.pow(2, sb.length());

        //replaces foremost block of contiguous 1's led by a 0 with 1000...000
        zeroIndex = sb.indexOf("011");
        sb.setCharAt(zeroIndex, '1');
        trailingZeroes = new char[sb.length() - zeroIndex - 1];
        Arrays.fill(trailingZeroes, '0');
        sb.replace(zeroIndex + 1, sb.length(), String.valueOf(trailingZeroes));
        return Integer.parseInt(sb.toString(), 2);
    }
}
