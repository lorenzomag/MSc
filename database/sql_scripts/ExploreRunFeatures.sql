SELECT DISTINCT r.ID AS "Run", f.Name AS "Feature", f.Parent AS "Base feature" FROM TMVA_runs r 
LEFT JOIN Feature_set_rel fr ON fr.set_ID == r.Feature_set
LEFT JOIN Features f ON fr.Feature_ID == f.ID;