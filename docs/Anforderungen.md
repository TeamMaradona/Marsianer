
# Funktionale Anforderungen

1. Erkennung der Bodenfeuchtigkeit 
	- Der Feuchtigkeitssensor muss die Feuchtigkeit des Bodens messen 
	- Der Sensor überprüft regelmäßig den Boden

2. Steuerung der Wasserpumpen
	- Arduino muss (entsprechende) Wasserpumpen aktivieren, wenn Feuchtigkeitssensor Trockenheit anzeigt
	- Arduino muss (entsprechende) Wasserpumpen deaktivieren, wenn Feuchtigkeitssensor einen bestimmten Feuchtigkeitswert erreicht hat (muss festgelegt werden)

3. Bewässerungsdauer 
	- Anhand der gemessen Bodenfeuchtigkeit muss die Dauer der Bewässerung reguliert werden 
	- Eine Maximalzeit muss festgelegt werden 

4. Individualität
	- Jede Pflanze muss individuell gemessen und versorgt werden

# Nicht-funktionale Anforderungen

1. Reaktionszeit
	- Nachdem Trockenheit gemessen wurde (Nachdem gewisser Schwellwert unterboten wurde), sollte das System innerhalb 1 Sekunden das erfassen und Bewässerung starten 
2. Zuverlässigkeit
	- 99% der Feuchtigkeitsmessung müssen korrekt ausgeführt werden (Trockenheit muss sicher erkannt werden)
3. Robustheit
	- System muss zuverlässig auch bei schwankender Netzspannung arbeiten
4. Sicherheit 
	- Wasserfestes System
5. Benutzerfreundlichkeit 
	- Das System ist einfach zu bedienen, Nutzer sollte am besten so wenig wie möglich "installieren"