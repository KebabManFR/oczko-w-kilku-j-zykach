Randomize

Dim graczP
Dim przeciwnikP
Dim graczSkonczyl
Dim przeciwnikSkonczyl

graczP = 0
przeciwnikP = 0
graczSkonczyl = False
przeciwnikSkonczyl = False

Function GetRandom(lower, upper)
    GetRandom = Int((upper - lower + 1) * Rnd + lower)
End Function

Function LosujKarte()
    Dim karta
    karta = GetRandom(1, 13)
    If karta >= 2 And karta <= 10 Then
        LosujKarte = karta
    ElseIf karta = 1 Then
        LosujKarte = 11
    ElseIf karta = 11 Then
        LosujKarte = 2
    ElseIf karta = 12 Then
        LosujKarte = 3
    ElseIf karta = 13 Then
        LosujKarte = 4
    End If
End Function

Sub dajKarteGraczu()
    Dim karta
    karta = LosujKarte()
    graczP = graczP + karta
    MsgBox "Otrzymales karte o wartosci " & karta & " (Suma punktów: " & graczP & ")", vbOKOnly, "Oczko"
End Sub

Sub dajKartePrzeciwnikowi()
    Dim karta
    karta = LosujKarte()
    przeciwnikP = przeciwnikP + karta
    MsgBox "Przeciwnik otrzymal karte o wartosci " & karta & " (Suma punktów: " & przeciwnikP & ")", vbOKOnly, "Oczko"
End Sub

MsgBox "Witamy w oczku!", vbOKOnly, "Oczko"
dajKarteGraczu()
dajKartePrzeciwnikowi()

While Not graczSkonczyl
    Dim response
    response = MsgBox("Czy chcesz dobrac karte?", vbYesNo, "Oczko")
    If response = vbYes Then
        dajKarteGraczu()
        If graczP > 21 Then
            MsgBox "Masz wiecej niz 21 punktow. Przegrales!", vbOKOnly, "Oczko"
            WScript.Quit
        End If
    Else
        graczSkonczyl = True
    End If
Wend

While Not przeciwnikSkonczyl
    If przeciwnikP < 17 Then
        dajKartePrzeciwnikowi()
        If przeciwnikP > 21 Then
            MsgBox "Przeciwnik ma wiecej niz 21 punktow. Wygrales!", vbOKOnly, "Oczko"
            WScript.Quit
        End If
    Else
        przeciwnikSkonczyl = True
    End If
Wend

MsgBox "Masz " & graczP & " punktow, przeciwnik ma " & przeciwnikP & " punktow.", vbOKOnly, "Oczko"
If graczP > przeciwnikP Then
    MsgBox "Wygrales!", vbOKOnly, "Oczko"
ElseIf graczP < przeciwnikP Then
    MsgBox "Przegrales!", vbOKOnly, "Oczko"
Else
    MsgBox "Remis!", vbOKOnly, "Oczko"
End If