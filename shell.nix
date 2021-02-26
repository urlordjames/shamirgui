{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
	buildInputs = with pkgs; [
		cmake
		ninja
		wxGTK31-gtk3
		gmp
		gmock
	];
}
