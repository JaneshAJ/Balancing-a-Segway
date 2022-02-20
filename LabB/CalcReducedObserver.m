function [Md1,Md2,Md3,Md4,Md5,Md6,Md7, L_red] = CalcReducedObserver(Ad,Bd,Cd,Dd,Cacc,Cinacc,poles)
% Ad = Ad;
% Bd = Bd;
% Cd = [1,0,0,0 ; 0,0,1,0];
% Cacc = [1,0,0,0]
% Dd = 0
% Cinacc = [ 0,0,1,0  ]
% V = [0,1,0,0 ; 0,0,1,0 ; 0,0,0,1]

dim = size(Cd);
dimInacc = size(Cinacc);
n = dim(2);
p = dim(1) - dimInacc(1);

V = eye(n) - Cacc'*Cacc;
V = V(any(V,2),:)
%%
T = inv([Cacc ; V])

A_ = inv(T) * Ad * T
B_ = inv(T) * Bd
Cacc_ = [eye(p) , zeros(p,n-p)]
Cinacc_ =  Cinacc * T
%%
Ayy_ = A_(1:p,1:p)
AyX_ = A_(1:p,p+1:n)
AXy_ = A_(p+1:n,1:p)
AXX_ = A_(p+1:n,p+1:n)

By_ = Bd(1:p,:)
BX_ = Bd(p+1:n,:)

Cy_ = Cinacc_(:,1:p)
CX_ = Cinacc_(:,p+1:n)

AA = AXX_
CC = [AyX_;CX_]
BB = [AXy_,BX_]
DD = zeros(2,1)

% eig(AA)

% sys_L = ss(AA,BB,CC,DD)


% L = ( place( AA', CC', [0 -854 -5.6]))'
L_red = ( place( AA', CC', poles))'

Lacc = L_red(:,1)
% Linacc = L(:,p+1:n)
Linacc = L_red(:,2)

Md1 = AXX_ - Lacc*AyX_ - Linacc*CX_ 
Md2 = BX_ - Lacc*By_
Md3 = AXy_ - Lacc*Ayy_ - Linacc*Cy_
Md4 = Linacc
Md5 = Lacc
Md6 = T(:, 1:p)
Md7 = T(:, p+1:n)
end