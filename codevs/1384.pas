var
    a:array[1..7] of longint;
    n,y,m,d,xq:longint;
begin
    readln(n);
    y:=1899; 
    m:=12;
    d:=31;
    xq:=7; 
    fillchar(a,sizeof(a),0);
    repeat
        inc(d);
        if (m=4) or (m=6) or (m=9) or (m=11) then begin 
            if d=31 then begin inc(m); d:=1; end;
        end
        else
        if (m<>2) then begin
            if d=32 then begin inc(m); d:=1; end;
        end
        else begin
            if ((y mod 100>0) and (y mod 4=0)) or ((y mod 100=0) and (y mod 400=0)) then begin
                if d=30 then begin inc(m); d:=1; end;
            end
            else begin
                if d=29 then begin inc(m); d:=1; end;
            end;
        end;
        if m=13 then begin inc(y); m:=1; end;
        inc(xq);
        if xq=8 then xq:=1;
        if d=13 then inc(a[xq]); 
    until (y=1900+n-1) and (m=12) and (d=31);
    write(a[6],' ',a[7]);
    for n:=1 to 5 do write(' ',a[n]);
    writeln;
end.