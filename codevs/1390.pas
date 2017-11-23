var
    i,n:longint;
function tentok(n,m:longint):string;
    var
        i:longint;
    function nts(n:longint):string;
        begin
            str(n,nts);
        end;
    begin
        tentok:='';
        repeat
            if (m>10) and (n mod m>9) then tentok:=chr((n mod m)+55)+tentok
            else tentok:=nts(n mod m)+tentok;
            n:=n div m;
        until n=0;
    end;
function ispalind(s:string):boolean;
    var
        i:longint;
    begin
        ispalind:=true;
        for i:=1 to length(s) div 2 do
            if s[i]<>s[length(s)-i+1] then begin ispalind:=false; break; end;
    end;
begin
    readln(n);
    for i:=1 to 300 do
        if ispalind(tentok(sqr(i),n)) then writeln(tentok(i,n),' ',tentok(sqr(i),n));
end.