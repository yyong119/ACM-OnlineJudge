var
        str1,str2,str3:ansistring; ch1,ch2,ch3:char;
        l1,l2,i:longint;
procedure change(var ch:char; num:longint);
begin
        case num of
                1:ch:=chr(ord(ch)+ord('Z')-ord('z'));
                2:ch:=chr(ord(ch)-ord('Z')+ord('z'));
                end;
end;
begin
        readln(str1); l1:=length(str1); readln(str2); l2:=length(str2);
        while l1<l2 do
        begin
                str1:=str1+str1;
                l1:=length(str1);
        end;
        for i:=1 to l2 do
        begin
                ch1:=str1[i]; ch2:=str2[i];
                if (ord(ch2)>=ord('a')) and (ord(ch2)<=ord('z')) then
                begin
                        if (ord(ch1)>=ord('A')) and (ord(ch1)<=ord('Z')) then change(ch1,2);
                        if ord(ch1)<=ord(ch2) then ch3:=chr(ord('a')+ord(ch2)-ord(ch1))
                                else ch3:=chr(ord('a')+ord(ch2)-ord(ch1)+26);
                end
                else
                if (ord(ch2)>=ord('A')) and (ord(ch2)<=ord('Z')) then
                begin
                        if (ord(ch1)>=ord('a')) and (ord(ch1)<=ord('z')) then change(ch1,1);
                        if ord(ch1)<=ord(ch2) then ch3:=chr(ord('A')+ord(ch2)-ord(ch1))
                                else ch3:=chr(ord('A')+ord(ch2)-ord(ch1)+26);
                end;
                str3:=str3+ch3;
        end;
        writeln(str3);
end.