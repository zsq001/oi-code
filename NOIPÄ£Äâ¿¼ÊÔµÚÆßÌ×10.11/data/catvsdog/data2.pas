var
  ss:string;
  s:ansistring;
  d,i,tt,ii,n,m:longint;

begin
  assign(input,'c.out');
  reset(input);
 // readln(tt);
 tt:=23;
  for ii:=1 to tt do
    begin
      str(ii,ss);
      assign(output,'catvsdog'+ss+'.out');
      rewrite(output);
      {readln(n,d,m);
      writeln(n,' ',d,' ',m);
      for i:=1 to m do
        begin  }
          readln(s);
          writeln(s);
       { end; }
      close(output);
    end;
  close(input);
end.
