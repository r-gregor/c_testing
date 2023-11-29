import java.util.*;
import java.math.BigDecimal;
import java.math.RoundingMode;

/**
 * Infinite_sum.java
 */
public class Infinite_sum {
	
	public static void pi_approx(long ninter) {
		double sum = 0.0;
		long cnt = 0;

		for (long i=1; i < ninter * 2; i += 2) {
			cnt += 1;
			if (cnt == 0) {
				sum = 1.0/i;
				// System.out.printf("cnt = %d, sum = %.20f\n",cnt, sum);
			} else if ((cnt % 2) == 0){
				sum = sum - (1.0/i);
				// System.out.printf("cnt = %d, sum = %.20f\n",cnt, sum);
			} else {
				sum = sum + (1.0/i);
				// System.out.printf("cnt = %d, sum = %.20f\n",cnt, sum);
			}
		}
		System.out.printf("PI approx after %d iterations: %.20f\n", ninter, (sum * 4));
	}



	public static void main(String[] args) {

		System.out.printf("PI approximation --> PI/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...\n");

		for (long num=0; num < 100000001; num += 5000000) {
			pi_approx(num);
		}
	}
}

