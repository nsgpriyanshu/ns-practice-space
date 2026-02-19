clc;
clear;
clf();

// Larger matrix sizes for visible difference
n = 10:10:1000;

// Time calculations
T_traditional = n.^3;
T_strassen = n.^2.81;

// Scale to billions for readability
T_traditional = T_traditional / 1000000000;
T_strassen = T_strassen / 1000000000;

// Plot Traditional (Red)
plot(n, T_traditional, 'r');

// Hold graph to add second curve
plot(n, T_strassen, 'b');

// Labels
xlabel("Matrix Size (n)");
ylabel("Time (in Billions of Basic Operations)");
title("Time Complexity Comparison: Traditional vs Strassen");

legend("Traditional O(n^3)", "Strassen O(n^2.81)");

xgrid();
