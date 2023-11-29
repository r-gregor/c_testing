import java.util.*;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class JavaPI {
	public static void main(String[] args) {
		System.out.println("Printing PI with 50 decimals - without & with BigDecimal:");
		System.out.printf("PI = %.50f\n", Math.PI);
		System.out.printf("PI = %.50f\n", new BigDecimal(Math.PI));
	}


}
