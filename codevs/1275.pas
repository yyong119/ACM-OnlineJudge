var
    a1,a2,a3,a4:longint;
begin
    readln(a1,a2,a3,a4);
    if (a1>a2)and(a2>a3)and(a3>a4) then writeln('Fish Diving')
        else if (a1=a2)and(a2=a3)and(a3=a4) then writeln('Fish At Constant Depth')
        else if (a1<a2)and(a2<a3)and(a3<a4) then writeln('Fish Rising')
        else writeln('No Fish');
end.