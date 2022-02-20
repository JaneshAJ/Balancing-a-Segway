A_param = sym('A_%d%d', [4 4]);
B_param = sym('B_%d%d', [4 1]);
C_param = sym('C_%d%d', [1 4]);
D_param = sym('D_%d%d', [1 1]);

Alpha = sym('alpha_%d%d', [4 4]);
Beta = sym('beta_%d%d', [4 1]);
Gamma = sym('gamma_%d%d', [4 4]);

Alpha(:,:) = 0;
Alpha(1,2) = 1;
Alpha(2,2) = ((2*K_e*K_t)/(R_m*l_w)) + (b_f/l_w);
Alpha(2,3) = m_b*l_b*g;
Alpha(2,4) = -((2*K_e*K_t)/R_m) - b_f;
Alpha(3,4) = 1;
Alpha(4,2) = -((2*K_e*K_t)/(R_m*l_w)) - (b_f/l_w);
Alpha(4,4) = ((2*K_e*K_t)/R_m) + b_f;

Beta(:,:) = 0;
Beta(2,1) = -2*K_t/R_m;
Beta(4,1) = 2*K_t/R_m;

Gamma(:,:) = 0;
Gamma(1,1) = 1;
Gamma(2,2) = m_b*l_b;
Gamma(2,4) = I_b + m_b*l_b^2;
Gamma(3,3) = 1;
Gamma(4,2) = (I_w/l_w) + l_w*m_b + l_w*m_w;
Gamma(4,4) = m_b * l_b * l_w;

A_param = Gamma\Alpha; %inv(Gamma)*Alpha
B_param = Gamma\Beta; %inv(Gamma)*Beta
C_param = [0, 0, 1, 0 ];
D_param = [0];

% to calculate with full acuracy
A = double(subs(A_param,PARAMS,VALUES));
B = double(subs(B_param,PARAMS,VALUES));
C = double(subs(C_param,PARAMS,VALUES));
D = double(subs(D_param,PARAMS,VALUES));
