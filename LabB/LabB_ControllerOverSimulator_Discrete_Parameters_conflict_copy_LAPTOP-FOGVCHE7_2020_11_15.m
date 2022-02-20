close all;
clear all;
clc;

% select the sampling time
fSamplingPeriod = 0.005;

%replace with your own gains
%Kd = [-1  -1  -1  -1];
% Desired Poles
P = [0,-843.4002,-5.6422,-5.642]
% P = [0,-5.642,-5.6422,-5.6]
    A = [0 , 1.0 , 0 , 0 ; 0 , -658.7 , -6.6 ,  13.8 ; 0 , 0 , 0 , 1.0 ; 0 , 2820.4 , 63.1 , -59.2] ;
    B = [0 , 0 ; 36.5980 , 1.8795 ; 0 , 0 ; -156.7072 , 1.0797];
    C = [ 0 , 0 , 1 , 0 ];
    D = [ 0 , 0 ];
    
%replace with your own values
K = place(A, B, P)
Kd=c2d(K,fSamplingPeriod,'zoh')


