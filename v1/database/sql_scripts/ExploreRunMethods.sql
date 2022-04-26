SELECT DISTINCT r.ID AS "Run", m.Name AS "MVA Method" FROM TMVA_runs r 
LEFT JOIN TMVA_method_sets s ON r.Method_set == s.set_ID 
LEFT JOIN TMVA_methods m ON s.Method_ID == m.ID;