#include "prime_factors.h"

namespace prime_factors {

std::vector<long long> of(long long n) {
    std::vector<long long> factors;

    // Wir starten mit dem kleinstmöglichen Primfaktor: 2
    // Die Schleife läuft nur so lange, wie das Quadrat des Teilers kleiner oder gleich n ist.
    for (long long divisor = 2; divisor * divisor <= n; ++divisor) {
        // Solange n ohne Rest durch den Teiler teilbar ist, fügen wir ihn zur Liste hinzu
        while (n % divisor == 0) {
            factors.push_back(divisor);
            n /= divisor; // n verkleinern
        }
    }

    // Wenn nach der Schleife n größer als 1 ist, bedeutet das, dass der verbleibende
    // Wert selbst eine Primzahl ist (z.B. bei großen Primfaktoren).
    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

}  // namespace prime_factors
