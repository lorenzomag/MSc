#define run_with_root

{
  gInterpreter->AddIncludePath("$WORKSPACE_DIR/feature_analysis/include");
  gInterpreter->ProcessLine(".L src/search.C++O");
  gInterpreter->ProcessLine(".L src/draw.C++O");
  gInterpreter->ProcessLine(".L src/select_features.C++O");
  gInterpreter->ProcessLine(".x src/main.C++O");
}
