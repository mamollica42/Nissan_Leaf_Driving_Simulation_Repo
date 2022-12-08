R1=1800;
R2=1300;
req=R1+R2;


for n = 0:20
    Vin=n;
    current = Vin/req;
    current = current *10 ^3;
    Vout=Vin*R2/req;
    fprintf('Vout:%f\n%:',Vout)
    fprintf('The Current from the Voltage divider: %f\n%',current);
    fprintf('------------------------------------\n');
end


