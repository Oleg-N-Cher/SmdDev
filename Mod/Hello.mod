MODULE Hello; (*$MAIN*)
IMPORT VDP_BG, SYS, Ignore;
BEGIN
  VDP_BG.DrawText("Hello world !", 12, 12);
  LOOP
    (* nothing to do here *)
    (* // ... *)

    (* always call this method at the end of the frame *)
    Ignore.Int(
      SYS.DoVBlankProcess())
  END
END Hello.
