{
  description = "YACM Development Environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.${system}.default = pkgs.mkShell.override {
      } {
        packages = with pkgs; [
						gnumake
						gcc16
						cmake
        ];
      };
    };
}
